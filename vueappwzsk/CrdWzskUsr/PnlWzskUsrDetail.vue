<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="1">
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtPrs"
				:label="tag.CptPrs"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtSrf"
				:label="tag.CptSrf"
			/>

			<v-divider/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.TxtUsg"
				:label="tag.CptUsg"
			/>

			<div
				class="my-1"
			>
				<!-- IP divJ - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupSte"
				:items="feedFPupSte"
				:label='tag.CptSte'
				v-on:change="handlePupChange('numFPupSte', contapp.fiFPupSte)"
				:disabled="!statshr.PupSteActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupLcl"
				:items="feedFPupLcl"
				:label='tag.CptLcl'
				v-on:change="handlePupChange('numFPupLcl', contapp.fiFPupLcl)"
				:disabled="!statshr.PupLclActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFPupUlv"
				:items="feedFPupUlv"
				:label='tag.CptUlv'
				v-on:change="handlePupChange('numFPupUlv', contapp.fiFPupUlv)"
				:disabled="!statshr.PupUlvActive"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfPwd"
				:label="tag.CptPwd"
				:disabled="!statshr.TxfPwdActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfFky"
				:label="tag.CptFky"
				:disabled="!statshr.TxfFkyActive"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.TxfCmt"
				:label="tag.CptCmt"
				:disabled="!statshr.TxfCmtActive"
			/>

		</v-card-text>
	</v-card>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWzskUsrDetail',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWzskUsrDetail.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(consref) {
				const dpchapp = {
					"DpchAppWzskUsrDetailDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": consref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(cisref, fi) {
				this.contiac[cisref] = fi.num;

				this.updateEng(["contiac"]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWzskUsrDetail"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWzskUsrDetailData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWzskUsrDetailData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWzskUsrDetail) this.contiac = dpcheng.ContIacWzskUsrDetail;
				if (dpcheng.ContInfWzskUsrDetail) this.continf = dpcheng.ContInfWzskUsrDetail;
				if (dpcheng.FeedFPupJ) this.feedFPupJ = dpcheng.FeedFPupJ;
				if (dpcheng.FeedFPupLcl) this.feedFPupLcl = dpcheng.FeedFPupLcl;
				if (dpcheng.FeedFPupSte) this.feedFPupSte = dpcheng.FeedFPupSte;
				if (dpcheng.FeedFPupUlv) this.feedFPupUlv = dpcheng.FeedFPupUlv;
				if (dpcheng.StatAppWzskUsrDetail) this.statapp = dpcheng.StatAppWzskUsrDetail;
				if (dpcheng.StatShrWzskUsrDetail) this.statshr = dpcheng.StatShrWzskUsrDetail;
				if (dpcheng.TagWzskUsrDetail) {
					Wzsk.unescapeBlock(dpcheng.TagWzskUsrDetail);
					this.tag = dpcheng.TagWzskUsrDetail;
				}
				if (dpcheng.ContIacWzskUsrDetail) {
					for (let i = 0; i < this.feedFPupJ.length; i++)
						if (this.feedFPupJ[i].num == this.contiac.numFPupJ) {
							this.contapp.fiFPupJ = this.feedFPupJ[i];
							break;
						}
					for (let i = 0; i < this.feedFPupSte.length; i++)
						if (this.feedFPupSte[i].num == this.contiac.numFPupSte) {
							this.contapp.fiFPupSte = this.feedFPupSte[i];
							break;
						}
					for (let i = 0; i < this.feedFPupLcl.length; i++)
						if (this.feedFPupLcl[i].num == this.contiac.numFPupLcl) {
							this.contapp.fiFPupLcl = this.feedFPupLcl[i];
							break;
						}
					for (let i = 0; i < this.feedFPupUlv.length; i++)
						if (this.feedFPupUlv[i].num == this.contiac.numFPupUlv) {
							this.contapp.fiFPupUlv = this.feedFPupUlv[i];
							break;
						}
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWzskVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWzskVDpch, dpcheng) {
				if (srefIxWzskVDpch == "DpchEngWzskUsrDetailData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWzskVDpch == "DpchEngWzskUsrDetailData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFPupJ: null,

			feedFPupLcl: null,

			feedFPupSte: null,

			feedFPupUlv: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFPupJ: null,

				fiFPupSte: null,

				fiFPupLcl: null,

				fiFPupUlv: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
